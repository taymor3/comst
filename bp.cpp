/* 046267 Computer Architecture - HW #1                                 */
/* This file should hold your implementation of the predictor simulator */

#include "bp_api.h"
#include <cmath>
#include <unordered_map>
#include <vector>
#include <cmath>

using namespace std;

class Data
{
private:
	uint32_t pc;
	int tag_size;
	int fsm_state;
	int is_share;
	int size;
	vector<int> local_hist;
	int index_hist;
	vector<int> local_table;
	int index_table;
	uint32_t dst;

public:
	Data(uint32_t pc, int tag_size, int fsm_state, int is_share, int size, bool use_table, bool use_hist, vector<int> *global_hist, vector<int> *global_tbl)
	{
		this->is_share = is_share;
		this->fsm_state = fsm_state;
		this->size = size;
		this->pc = pc;
		this->index_hist = 0;
		this->index_table = 0;
		this->tag_size = tag_size;
		if (use_table)
		{
			this->local_table = vector<int>(pow(2, size) - 1);
			init_table();
		}
		else
		{
			this->local_table = *global_tbl;
		}

		if (use_hist)
		{
			this->local_hist = vector<int>(size);
		}
		else
		{
			this->local_hist = *global_hist;
		}
		dst = pc + 4;
	}

	~Data(); // need checking if deletes new

	void update_hist(int bit)
	{ // need check

		this->local_hist[index_hist] = bit;
		index_hist = (index_hist + 1) % this->local_hist.size();
	}

	void update_table(int bit, uint32_t pc)
	{ // need check
		int index = 0;
		if (is_share == 0)
		{
			this->local_table[get_val_hist()] = bit;
		}
		else if (is_share == 1)
		{
			index = get_val_hist() ^ (pc >> 2);
			local_table[index] = bit;
		}
		else
		{
			index = get_val_hist() ^ (pc >> 16);
			local_table[index] = bit;
		}
	}

	int get_val_hist()
	{ // need check
		int sum = 0;
		for (int i = 0; i < local_hist.size(); i++)
		{
			sum += pow(2, i) * local_hist[i];
		}
		return sum;
	}

	void init_table()
	{
		for (int i = 0; i < local_table.size(); i++)
		{
			local_table[i] = this->fsm_state;
		}
	}

	uint32_t data_predict(bool *flag)
	{

		if (local_table[get_val_hist()] == 0 || local_table[get_val_hist()] == 1)
		{
			*flag = false;
			return uint32_t(this->pc + 4);
		}
		*flag = true;
		return this->dst;
	}

	void update(uint32_t pc, uint32_t targetPc, bool taken, uint32_t pred_dst)
	{
		if (taken)
		{
			update_table((local_table[get_val_hist()] + 1) > 4 ? 4 : (local_table[get_val_hist()] + 1), pc);
			update_hist(1);
		}
		else
		{
			update_table((local_table[get_val_hist()] - 1) < 0 ? 0 : (local_table[get_val_hist()] - 1), pc);
			update_hist(0);
		}
		// if pred_dst == traget_pc add some thing to sim_state_table

		this->dst = targetPc;
	}
};

class BTB
{
private:
	unordered_map<uint32_t, Data> map;
	vector<int> *global_hist; // check if need unit32_t might not work int
	vector<int> *global_table;
	int map_size;
	int hist_size;
	int tag_size;
	int fsm_state;
	bool is_global_table;
	bool is_global_hist;
	int shared;

public:
	BTB(unsigned btbSize, unsigned historySize, unsigned tagSize, unsigned fsmState,
		bool isGlobalHist, bool isGlobalTable, int Shared)
	{
		this->map_size = btbSize;
		this->hist_size = historySize;
		this->tag_size = tagSize;
		this->fsm_state = fsmState;
		this->is_global_table = isGlobalTable;
		this->is_global_hist = isGlobalHist;
		this->shared = Shared;
		if (is_global_table)
		{
			global_table = &vector<int>(pow(2, hist_size) - 1); // could be pointer
		}
		if (is_global_hist)
		{
			global_hist = &vector<int>(historySize);
		}
	}
	~BTB() = default;

	void add_pc(uint32_t pc)
	{ // need to check if we find pc
		if (map.find(pc) == map.end())
		{
			Data *data =new  Data(pc, this->tag_size, fsm_state, this->shared, this->hist_size, !is_global_table, !is_global_hist, this->global_hist, this->global_table);
			this->map.insert(make_pair(pc, *data));
		}
	}
	bool predict(uint32_t pc, uint32_t *dst)
	{
		add_pc(pc); // need to check if NT, we have to add or not
		Data d =this->map[pc];
		bool f;
		*dst= d.data_predict(&f);
		if (f)
		{
			return true;
		}
		return false;
	}
	void update(uint32_t pc, uint32_t targetPc, bool taken, uint32_t pred_dst)
	{
		Data d = map[pc];
		d.update(pc, targetPc, taken, pred_dst);

	} // here
};

BTB * btb; // global btb
int BP_init(unsigned btbSize, unsigned historySize, unsigned tagSize, unsigned fsmState,
			bool isGlobalHist, bool isGlobalTable, int Shared)
{ // init a BTB variable
	btb = new BTB(btbSize, historySize, tagSize, fsmState, isGlobalHist, isGlobalTable, Shared);
	if (&btb == NULL)
	{
		return -1;
	}
	return 1;
}

bool BP_predict(uint32_t pc, uint32_t *dst)
{
	return btb->predict(pc, dst);
}

void BP_update(uint32_t pc, uint32_t targetPc, bool taken, uint32_t pred_dst)
{
	btb->update(pc, targetPc, taken, pred_dst);
}

void BP_GetStats(SIM_stats *curStats)
{

	return;
}
