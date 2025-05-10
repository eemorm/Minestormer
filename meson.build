project('Minestormer', 'cpp',
  version : '0.1',
  default_options : ['warning_level=3', 'cpp_std=c++20'])

sfml_dep = dependency('sfml', method : 'pkg-config')

executable('Minestormer',
           'src/main.cpp',
           'src/textures.cpp',
           'src/cell.cpp',
           'src/grid.cpp',
           'src/sizing.cpp',
           'src/generation.cpp',
           'src/death.cpp',
           install : true,
           dependencies: [sfml_dep])
