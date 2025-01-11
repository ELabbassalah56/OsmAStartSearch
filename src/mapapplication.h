#pragma once
#include <optional>
#include <iostream>
#include <vector>
#include <string>
#include <io2d.h>
#include "route_model.h"
#include "render.h"
#include "route_planner.h"


using namespace std::experimental;


class mapapplication final
{
    public:
    mapapplication(); // default
    mapapplication(mapapplication & other) noexcept = delete;
    mapapplication(mapapplication && other) noexcept = delete;
    mapapplication& operator=(const mapapplication& other) noexcept = delete;
    mapapplication& operator=(mapapplication&& other) noexcept;
    ~mapapplication(); // deafult
    void Run(std::vector<std::byte>& osm_data);
};