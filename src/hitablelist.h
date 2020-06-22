#pragma once

#include <hitable.h>

#include <memory>
#include <vector>

using std::shared_ptr;
using std::make_shared;

namespace AMB
{

class hitable_list: public hitable
{
public:
    hitable_list();
    hitable_list (shared_ptr<hitable> object);

    void clear();
    void add (shared_ptr<hitable> object);
    bool hit (const ray& r, float tmin, float tmax, hit_record& rec) const override;
private:    
    std::vector<shared_ptr<hitable>> _objects;
};

} // end of namespace AMB
