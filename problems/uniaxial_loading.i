#
# Initial single block mechanics input
# https://mooseframework.inl.gov/modules/tensor_mechanics/tutorials/introduction/step01.html
#

[GlobalParams]
  displacements = 'disp_x disp_y'
[]

[Mesh]
  [generated]
    type = GeneratedMeshGenerator
    dim = 2
    nx = 10
    ny = 10
    xmax = 2
    ymax = 1
  []
[]

[Modules/TensorMechanics/Master]
  [all]
    strain = SMALL
    add_variables = true
  []
[]

[BCs]
  [bottom_x]
    type = DirichletBC
    variable = disp_x
    boundary = bottom
    value = 0
  []
  [bottom_y]
    type = DirichletBC
    variable = disp_y
    boundary = bottom
    value = 0
  []
  [Pressure]
    [top]
      boundary = top
      function = 1e7*t
    []
  []
[]

[Materials]
  [elasticity]
    type = ComputeIsotropicElasticityTensor
    youngs_modulus = 1e9
    poissons_ratio = 0.3
  []
  [stress]
    type = ComputeLinearElasticStress
  []
[]

[Executioner]
  type = Transient
  end_time = 5
  dt = 1
[]

[Outputs]
  exodus = true
[]