#ifndef CSLIBS_MAPPING_OCCUPANCY_NDT_GRID_MAP_2D_HPP
#define CSLIBS_MAPPING_OCCUPANCY_NDT_GRID_MAP_2D_HPP

#include <cslibs_mapping/maps/map.hpp>
#include <cslibs_ndt_2d/dynamic_maps/occupancy_gridmap.hpp>

namespace cslibs_mapping {
namespace maps {
class OccupancyNDTGridMap2D : public Map
{
public:
    using Ptr      = std::shared_ptr<OccupancyNDTGridMap2D>;
    using ConstPtr = std::shared_ptr<const OccupancyNDTGridMap2D>;

    using map_t    = cslibs_ndt_2d::dynamic_maps::OccupancyGridmap;
    template <typename ... args_t>
    inline OccupancyNDTGridMap2D(const std::string &frame,
                                 const args_t &...args) :
        Map(frame),
        map_(new map_t(args...))
    {
    }

    const inline map_t::Ptr get() const
    {
        return map_;
    }

private:
    const map_t::Ptr map_;
};
}
}

#endif // CSLIBS_MAPPING_OCCUPANCY_NDT_GRID_MAP_2D_HPP
