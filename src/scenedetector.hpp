#include <string>

typedef struct {
    int start;
    int end;
} SceneDetection;

SceneDetection* detect_scenes(
    std::string videopath,
    int gradualHeuristic,
    float swIntersection,
    float swEuclidean,
    float localSWIntersection,
    float localSWEuclidean, 
    int& numScenes
);
