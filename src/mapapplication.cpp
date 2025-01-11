#include "mapapplication.h"

mapapplication::mapapplication()
{
    // do nothing
}

void mapapplication::Run(std::vector<std::byte> &osm_data)
{
    float motionPoints[4]={0.0, 0.0, 0.0, 0.0};
    std::cout<<"Please fill the coardinates in one line start x point and y point: ";
    std::cin>>motionPoints[0]>>motionPoints[1];
        std::cout<<"Please fill the coardinates in one line end x point and y point: ";
    std::cin>>motionPoints[2]>>motionPoints[3];
    // Build Model.
    RouteModel model{osm_data};

    // Create RoutePlanner object and perform A* search.
    RoutePlanner route_planner{model, motionPoints[0], motionPoints[1], motionPoints[2], motionPoints[3]};
    route_planner.AStarSearch();

    std::cout << "Distance: " << route_planner.GetDistance() << " meters. \n";

    // Render results of search.
    Render render{model};

    auto display = io2d::output_surface{400, 400, io2d::format::argb32, io2d::scaling::none, io2d::refresh_style::fixed, 30};
    display.size_change_callback([](io2d::output_surface& surface){
        surface.dimensions(surface.display_dimensions());
    });
    display.draw_callback([&](io2d::output_surface& surface){
        render.Display(surface);
    });
    display.begin_show();
}

mapapplication::~mapapplication(){}