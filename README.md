# LABO 02 - MANDELBROT 

Boris Hutzli, Robin Forestier

## But

Le but de ce deuxième laboratoire est de réaliser une visualisation d'une fractale de Mandelbrot.

## Utilisation / Configuration



## Pseudo code

Pour réaliser notre programme, nous devons nous baser sur le pseudo-code de wikipedia :

[W Mandelbrot set](https://en.wikipedia.org/wiki/Mandelbrot_set#Computer_drawings)

```
for each pixel (Px, Py) on the screen do
    x0 := scaled x coordinate of pixel (scaled to lie in the Mandelbrot X scale (-2.00, 0.47))
    y0 := scaled y coordinate of pixel (scaled to lie in the Mandelbrot Y scale (-1.12, 1.12))
    x := 0.0
    y := 0.0
    iteration := 0
    max_iteration := 1000
    while (x*x + y*y ≤ 2*2 AND iteration < max_iteration) do
        xtemp := x*x - y*y + x0
        y := 2*x*y + y0
        x := xtemp
        iteration := iteration + 1
    
    color := palette[iteration]
    plot(Px, Py, color)    
```

## Fichiers

### main

### mandelbrot

### display

### animation

  