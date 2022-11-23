cimport scenedetector
cimport numpy as np

import numpy as np


def detect_scenes(videopath : str, gradualHeuristic : int = 3,
    swIntersection : float = 0.25,
    swEuclidean : float = 1.5,
    localSWIntersection : float = 0.5,
    localSWEuclidean : float = 9.0
):
    cdef scenedetector.SceneDetection* scenes
    cdef int scene_count = 0
    cdef long[:, :] scene_list
    scenes = scenedetector.detect_scenes(videopath.encode('utf8'), 3, 0.25, 1.5, 0.5, 9.0, scene_count)
    scene_list = np.zeros((scene_count, 2), dtype=long) 

    for i in range(scene_count):
        scene_list[i, 0] = scenes[i].start
        scene_list[i, 1] = scenes[i].end

    return np.asarray(scene_list)