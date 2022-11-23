# Scene Detect
FAST es una librería de detección de cambios de escenas desarrollada en C++. EL código fuente original puede encontrarse en https://github.com/Trojahn/FAST

Este repositorio contiene un wrapper para Python de dicha librería.

# Instalación
```
python3 setup.py install
```

# Uso
```python
import fastscenedetect import detect_scenes
scenes = detect_scenes("example.mp4")
print(scenes)
```

El resultado es un array de numpy con `n` filas y 2 columnas. Cada fila corresponde al frame inicial y final de la escena.

```python
array([[   1,  139],
       [ 140,  203],
       [ 204,  802],
       [ 803,  825],
       [ 826,  892],
       [ 893,  920],
       [ 921, 1003],
       [1004, 1046],
       [1048, 1638],
       [1639, 1690],
       [1691, 1954],
       [1955, 2058],
       [2060, 2230],
       [2231, 2587],
       [2588, 2711],
       [2712, 2800],
       [2801, 3000]])
```

La función `detect_scenes` tiene por argumentos:
```python
videopath : str
swIntersection : float = 0.25,
swEuclidean : float = 1.5,
localSWIntersection : float = 0.5,
localSWEuclidean : float = 9.0
```