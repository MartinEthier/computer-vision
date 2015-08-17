#ifndef FRAME_H_INCLUDED
#define FRAME_H_INCLUDED

/**
 * @file frame.h
 *
 * @brief Container class for storing photos or frames of video to be
 *        processed and analyzed
 *
 */

#include <opencv2/core/core.hpp>
#include "target.h"
#include "metadata.h"
#include "pixel_target.h"
#include <vector>

class Frame{
public:
    Frame(std::Mat img, std::string id, Metadata m);
    
    /**
     * @brief 
     *
     * @return timestamp identifier for the frame
     */
    std::string get_id();

    /**
     * @brief 
     *
     * @return image associated with the frame
     */
    cv::Mat & get_img(); 

    /**
     * @brief Adds given target to the list of targets 
     *
     * @param t target identified as being in the frame
     */
    void add_target(PixelTarget * t);

    /**
     * @brief getter for targets
     *
     * @return iterator pointing at the first target in the target list
     */
    iterator get_targets();

    /** 
     * @brief getter for metadata
     *
     * @return const pointer to internal metadata structure
     */
    const Metadata * get_metadata();
private:
    
    /**
     * @brief image associated with the Frame 
     */
    cv::Mat img;

    /**
     * @brief Timestamp for the frame
     */
    std::string id;

    /**
     * @brief Data collected from telemetry about the plane when the image was captured
     */
    Metadata data;

    /**
     * @brief Targets that appear in the frame
     */
    vector<Target *> targets;
};


#endif // FRAME_H_INCLUDED