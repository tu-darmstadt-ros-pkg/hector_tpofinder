/**
 * Copyright (c) 2012 Andreas Heider, Julius Adorf, Markus Grimm
 *
 * MIT License (http://www.opensource.org/licenses/mit-license.php)
 */

#include "tpofinder/feature.h"

#include <stdexcept>

using namespace std;
using namespace cv;

namespace tpofinder {

    Feature::Feature() :
    /*        */ detector(cv::ORB::create()),
    /*        */ extractor(cv::ORB::create()),
    /*        */ matcher(cv::FlannBasedMatcher::create()) {
        validate();
    }

    Feature::Feature(const Ptr<FeatureDetector> detector,
            const Ptr<DescriptorExtractor> extractor,
            const Ptr<DescriptorMatcher> matcher) :
    /*        */ detector(detector),
    /*        */ extractor(extractor),
    /*        */ matcher(matcher) {
        validate();
    }

    void Feature::validate() {
        if (detector == NULL) {
            throw runtime_error("Feature detector not initialized.");
        }
        if (extractor == NULL) {
            throw runtime_error("Descriptor extractor not initialized.");
        }
        if (matcher == NULL) {
            throw runtime_error("Descriptor matcher not initialized.");
        }
    }

}
