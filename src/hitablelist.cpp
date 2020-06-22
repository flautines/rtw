#include <hitablelist.h>

namespace AMB
{

/////////////////////////////////////////////////////////////////////
//    
hitable_list::hitable_list()
{

}
/////////////////////////////////////////////////////////////////////
//
hitable_list::hitable_list(shared_ptr<hitable> object)
{
    add (object);
}
/////////////////////////////////////////////////////////////////////
//
void hitable_list::clear()
{
    _objects.clear();
}
/////////////////////////////////////////////////////////////////////
//
void hitable_list::add(shared_ptr<hitable> object)
{
    _objects.push_back (object);
}
/////////////////////////////////////////////////////////////////////
//
bool hitable_list::hit (const ray& r, float t_min, float t_max, hit_record& rec) const
{
    hit_record tmp_rec;
    bool hit_anything = false;
    double closest_so_far = t_max;

    for (const auto& object : _objects)
    {
        if (object->hit (r, t_min, closest_so_far, tmp_rec))
        {
            hit_anything = true;
            closest_so_far = tmp_rec.t;
            rec = tmp_rec;
        }
    }
    return hit_anything;
}

} // end of namespace AMB
