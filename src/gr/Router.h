#include "global.h"
#include "db/Database.h"

#include "Rpath.h"
#include "Vertex.h"

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

    vector<Rpath> rpaths;
    vector<vector<Point>> rpoints;
    vector<db::Net*> net_queue;
    vector<bool> net_rflag;
    vector<int> net_ovfl;
    priority_queue<std::shared_ptr<net_prior>> net_queue_ovfl;
    

public:
    Router(db::Database* database_);
    utils::logger* logger;

    bool single_net_pattern(db::Net* net);
    bool patter_route();
    bool single_net_maze(db::Net* net);
    bool unroute_net(db::Net* net);
    bool break_ovfl();
    void print_demand();
    void run();
    void write(const string& output_path);
    void ripup(const vector<int>& netsToRoute);
};

}