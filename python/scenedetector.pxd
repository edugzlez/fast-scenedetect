from libcpp.string cimport string

cdef extern from "scenedetector.hpp":
    ctypedef struct SceneDetection:
        int start
        int end

    SceneDetection* detect_scenes(string, int, float, float, float, float, int)

