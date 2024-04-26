
#pragma once

#include "vp_control_meta.h"

namespace vp_objects {
    // control meta for video recording, it is a specific type of vp_control_meta.
    // when vp_record_node handle this control meta, the node will start recording video asynchronously, begin with the Latest Next frame in pipeline (pre-record frames excluded).
    // refer to ./nodes/record/README.md for more details
    class vp_video_record_control_meta: public vp_control_meta {
    private:
        /* data */
    public:
        vp_video_record_control_meta(int channel_index, 
                                    std::string video_file_name_without_ext, 
                                    int record_video_duration = 0,
                                    bool osd = false);
        ~vp_video_record_control_meta();

        // copy myself
        virtual std::shared_ptr<vp_meta> clone() override;

        // file name without extension, like 2022-10-20_22-30-20_aaa_bbb, which should be a meaningful and unique name.
        // generated by sender who want to record video
        std::string video_file_name_without_ext;

        // record video duration (seconds), not including pre-record time.
        // 0 means using the value setted by vp_record_node.
        int record_video_duration = 0;

        // record type (osd frame or not)
        bool osd = false;
    };

}