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
    struct BTBEntry {
        uint32_t tag;                       // Tag for the BTB entry
        std::unique_ptr<Data> data;        // Pointer to Data object
        bool valid;                        // Whether the entry is valid

        BTBEntry() : tag(0), valid(false) {}
    };

    std::vector<BTBEntry> table;          // Fixed-size BTB table
    int btbSize;                          // Number of entries in the BTB
    int tagSize;
    int histSize;
    int fsmState;
    bool isGlobalTable;
    bool isGlobalHist;
    int shared;
    std::vector<int> global_hist;
    std::vector<int> global_table;

    int compute_index(uint32_t pc) {
        return (pc >> 2) & (btbSize - 1); // Direct-mapped index
    }

    uint32_t compute_tag(uint32_t pc) {
        return (pc >> (2 + log2(btbSize))) & ((1 << tagSize) - 1);
    }

public:
    BTB(unsigned btbSize, unsigned histSize, unsigned tagSize, unsigned fsmState,
        bool isGlobalTable, bool isGlobalHist, int shared)
        : btbSize(btbSize), histSize(histSize), tagSize(tagSize), fsmState(fsmState),
          isGlobalTable(isGlobalTable), isGlobalHist(isGlobalHist), shared(shared),
          table(btbSize) { // Initialize BTB table with btbSize entries
        if (isGlobalTable) {
            global_table.assign(1 << histSize, fsmState);
        }
        if (isGlobalHist) {
            global_hist.assign(histSize, 0);
        }
    }

    bool predict(uint32_t pc, uint32_t *dst) {
        int index = compute_index(pc);
        uint32_t tag = compute_tag(pc);

        BTBEntry &entry = table[index];
        if (entry.valid && entry.tag == tag) {
            // Tag matches, use the entry for prediction
            bool flag;
            *dst = entry.data->data_predict(&flag);
            return flag;
        }

        // Tag mismatch or entry invalid, predict not taken
        *dst = pc + 4;
        return false;
    }

    void update(uint32_t pc, uint32_t targetPc, bool taken, uint32_t pred_dst) {
        int index = compute_index(pc);
        uint32_t tag = compute_tag(pc);

        BTBEntry &entry = table[index];
        if (!entry.valid || entry.tag != tag) {
            // Initialize the entry if tag mismatch or invalid
            entry.valid = true;
            entry.tag = tag;
            entry.data = std::make_unique<Data>(
                pc, tagSize, fsmState, shared, histSize,
                !isGlobalTable, !isGlobalHist, &global_hist, &global_table);
        }

        // Update the entry
        entry.data->update(pc, targetPc, taken, pred_dst);
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
