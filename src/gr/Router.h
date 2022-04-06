#include "global.h"
#include "db/Database.h"

#include "Rpath.h"

namespace gr {

class Router {
public:
    db::Database* database;
    int gridX;
    int gridY;
    int capH = 0;
    int capV = 0;
    vector<vector<int>> demH;
    vector<vector<int>> demV;
    db::GRGrid grGrid;
    vector<vector<db::GCell*>> gcells;

    vector<db::Net*> net_queue;
    vector<Rpath> rpaths;
    vector<vector<db::Point>> rpoints;

public:
    Router(db::Database* database_);
    utils::logger* logger;

    bool single_net_pattern(db::Net* net);
    void print_demand();
    void run();
    void write(const string& output_path);
    void ripup(const vector<int>& netsToRoute);
};

}