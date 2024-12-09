/* 046267 Computer Architecture - HW #1                                 */
/* This file holds an improved implementation of the predictor simulator */

#include "bp_api.h"
#include <cmath>
#include <unordered_map>
#include <vector>
#include <memory>

using namespace std;

enum FSMState {
    SNT = 0, // Strongly Not Taken
    WNT = 1, // Weakly Not Taken
    WT = 2,  // Weakly Taken
    ST = 3   // Strongly Taken
};

class Data {
private:
    uint32_t pc;
    int tag_size;
    int fsm_state;
    int is_share;
    int size;
    vector<int> local_hist;
    vector<int> local_table;
    uint32_t dst;

public:
    Data(uint32_t pc, int tag_size, int fsm_state, int is_share, int size, bool use_table, bool use_hist, vector<int> *global_hist, vector<int> *global_tbl) 
        : pc(pc), tag_size(tag_size), fsm_state(fsm_state), is_share(is_share), size(size), dst(pc + 4) {

        if (use_table) {
            local_table.assign(1 << size, fsm_state);
        } else {
            local_table = *global_tbl;
        }

        if (use_hist) {
            local_hist.assign(size, 0);
        } else {
            local_hist = *global_hist;
        }
    }

    void update_hist(int bit) {
        local_hist.push_back(bit);
        if (local_hist.size() > size) {
            local_hist.erase(local_hist.begin());
        }
    }

    void update_table(int bit, uint32_t pc) {
        int index = get_index(pc);
        local_table[index] = bit;
    }

    int get_index(uint32_t pc) {
        int index = 0;
        for (int i = 0; i < local_hist.size(); i++) {
            index += (1 << i) * local_hist[i];
        }
        if (is_share == 1) {
            index ^= (pc >> 2);
        } else if (is_share == 2) {
            index ^= (pc >> 16);
        }
        return index;
    }

    uint32_t data_predict(bool *flag) {
        int index = get_index(pc);
        if (local_table[index] == SNT || local_table[index] == WNT) {
            *flag = false;
            return pc + 4;
        }
        *flag = true;
        return dst;
    }

    void update(uint32_t pc, uint32_t targetPc, bool taken, uint32_t pred_dst) {
        int index = get_index(pc);
        if (taken) {
            local_table[index] = (local_table[index] + 1) > ST ? ST : (local_table[index] + 1);
            update_hist(1);
        } else {
            local_table[index] = (local_table[index] - 1) < SNT ? SNT : (local_table[index] - 1);
            update_hist(0);
        }
        dst = targetPc;
    }
};

class BTB {
private:
    unordered_map<uint32_t, unique_ptr<Data>> map;
    vector<int> global_hist;
    vector<int> global_table;
    int map_size;
    int hist_size;
    int tag_size;
    int fsm_state;
    bool is_global_table;
    bool is_global_hist;
    int shared;

public:
    BTB(unsigned map_size, unsigned hist_size, unsigned tag_size, unsigned fsm_state,
        bool is_global_table, bool is_global_hist, int shared)
        : map_size(map_size), hist_size(hist_size), tag_size(tag_size), fsm_state(fsm_state),
          is_global_table(is_global_table), is_global_hist(is_global_hist), shared(shared) {

        if (is_global_table) {
            global_table.assign(1 << hist_size, fsm_state);
        }
        if (is_global_hist) {
            global_hist.assign(hist_size, 0);
        }
    }

    void add_pc(uint32_t pc) {
        if (map.find(pc) == map.end()) {
            map[pc] = make_unique<Data>(pc, tag_size, fsm_state, shared, hist_size, !is_global_table, !is_global_hist, &global_hist, &global_table);
        }
    }

    bool predict(uint32_t pc, uint32_t *dst) {
        add_pc(pc);
        Data &d = *map[pc];
        bool flag;
        *dst = d.data_predict(&flag);
        return flag;
    }

    void update(uint32_t pc, uint32_t targetPc, bool taken, uint32_t pred_dst) {
        if (map.find(pc) != map.end()) {
            map[pc]->update(pc, targetPc, taken, pred_dst);
        }
    }
};

BTB *btb;

int BP_init(unsigned btbSize, unsigned historySize, unsigned tagSize, unsigned fsmState,
            bool isGlobalHist, bool isGlobalTable, int Shared) {
    btb = new BTB(btbSize, historySize, tagSize, fsmState, isGlobalTable, isGlobalHist, Shared);
    if (!btb) {
        return -1;
    }
    return 1;
}

bool BP_predict(uint32_t pc, uint32_t *dst) {
    return btb->predict(pc, dst);
}

void BP_update(uint32_t pc, uint32_t targetPc, bool taken, uint32_t pred_dst) {
    btb->update(pc, targetPc, taken, pred_dst);
}

void BP_GetStats(SIM_stats *curStats) {
    // Placeholder for stats collection
    return;
}
