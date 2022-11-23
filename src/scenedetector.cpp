#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "Utils.hpp"
#include "ShotSegmentation.hpp"
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <utility>
#include <algorithm>
#include "scenedetector.hpp"

using namespace std;
using namespace cv;


SceneDetection* detect_scenes(
    string videopath,
    int gradualHeuristic,
    float swIntersection,
    float swEuclidean,
    float localSWIntersection,
    float localSWEuclidean, 
    int& numScenes
) {
    // Extract the video histograms
    vector<Mat> histograms = Utils::extractVideoHistograms(videopath);
    vector<pair<int,int>> shots = vector<pair<int,int>>();
    if(histograms.size() > 0) {
        ShotSegmentation ss(histograms);

        // Seting the needed thresholds.
        ss.setGradualThreshold(gradualHeuristic);
        ss.setSlidingWindowsIntersect(swIntersection);
        ss.setSlidingWindowsEuclidean(swEuclidean);
        ss.setLocalSlidingWindowIntersect(localSWIntersection);
        ss.setLocalSlidingWindowEuclidean(localSWEuclidean);

        // Performing the shotSegmentation
         shots = ss.segment();
    }

    SceneDetection* sceneDetections = new SceneDetection[shots.size()];
    for(int i = 0; i < (int) shots.size(); i++) {
        sceneDetections[i].start = shots[i].first;
        sceneDetections[i].end = shots[i].second;
    }
    numScenes = shots.size();
    return sceneDetections;

}
