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
hitable_list::hitable_list (hitable** l, int n) :
    _list { l }, _list_size { n }
{

}
/////////////////////////////////////////////////////////////////////
//
bool hitable_list::hit (const ray& r, float t_min, float t_max, hit_record& rec) const
{
    hit_record tmp_rec;
    bool hit_anything = false;
    double closest_so_far = t_max;

    for (int i = 0; i < _list_size; i++)
    {
        if (_list[i]->hit (r, t_min, closest_so_far, tmp_rec))
        {
            hit_anything = true;
            closest_so_far = tmp_rec.t;
            rec = tmp_rec;
        }
    }
    return hit_anything;
}

} // end of namespace AMB
