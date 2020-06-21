#pragma once

#include <hitable.h>

namespace AMB
{

class hitable_list: public hitable
{
public:
    hitable_list();
    hitable_list (hitable** l, int n);
    bool hit (const ray& r, float tmin, float tmax, hit_record& rec) const override;
private:    
    hitable** _list;
    int _list_size;
};

} // end of namespace AMB
