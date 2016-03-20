#include <stdlib.h>
#include "daala/include/daala/daalaenc.h"
#include "daala/include/daala/daaladec.h"

daala_info* daala_info_create(int32_t width, int32_t height,
                              uint32_t aspect_num, uint32_t aspect_den,
                              uint32_t timebase_num, uint32_t timebase_den,
                              int keyframe_rate)
{
    daala_info *di = (daala_info*)malloc(sizeof(daala_info));
    daala_info_init(di);
    di->pic_width = width;
    di->pic_height = height;
    di->pixel_aspect_numerator = aspect_num;
    di->pixel_aspect_denominator = aspect_den;
    di->timebase_numerator = timebase_num;
    di->timebase_denominator = timebase_den;
    di->frame_duration = 1;
    di->bitdepth_mode = OD_BITDEPTH_MODE_8;
    di->nplanes = 3;
    di->plane_info[0].xdec = 0;
    di->plane_info[0].ydec = 0;
    di->plane_info[1].xdec = 1;
    di->plane_info[1].ydec = 1;
    di->plane_info[2].xdec = 1;
    di->plane_info[2].ydec = 1;
    di->keyframe_rate = keyframe_rate;
    return di;
}

daala_comment *daala_comment_create()
{
    daala_comment *dc = (daala_comment*)malloc(sizeof(daala_comment));
    daala_comment_init(dc);
    return dc;
}

daala_image *daala_image_create(int32_t width, int32_t height)
{
    daala_image *di = (daala_image*)malloc(sizeof(daala_image));
    if (width > 0 && height > 0) {
        di->width = width;
        di->height = height;
        di->nplanes = 3;
        di->planes[0].data = (unsigned char*)malloc(width * height);
        di->planes[0].xdec = 0;
        di->planes[0].ydec = 0;
        di->planes[0].xstride = 1;
        di->planes[0].ystride = width;
        di->planes[0].bitdepth = 8;
        di->planes[1].data = (unsigned char*)malloc(width * height / 2);
        di->planes[1].xdec = 1;
        di->planes[1].ydec = 1;
        di->planes[1].xstride = 1;
        di->planes[1].ystride = width / 2;
        di->planes[1].bitdepth = 8;
        di->planes[2].data = (unsigned char*)malloc(width * height / 2);
        di->planes[2].xdec = 1;
        di->planes[2].ydec = 1;
        di->planes[2].xstride = 1;
        di->planes[2].ystride = width / 2;
        di->planes[2].bitdepth = 8;
    }
    return di;
}
