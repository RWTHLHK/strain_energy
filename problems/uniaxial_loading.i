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

[Variables]
  [disp_x]
    order = FIRST
    family = LAGRANGE
  []
  [disp_y]
    order = FIRST
    family = LAGRANGE
  []
[]

[AuxVariables]
    [tensile_strain_energy]
        family = LAGRANGE
        order = FIRST
    []
    [max_strain_energy]
        family = LAGRANGE
        order = FIRST
    []
[]


[Kernels]
  [TensorMechanics]
    #Stress divergence kernels
    displacements = 'disp_x disp_y'
   []
[]

[AuxKernels]
    [TensileStrainEnergy]
        type = TensileStrainEnergyAux
        rank_two_tensor = mechanical_strain
        variable = tensile_strain_energy
        lambda = 120
        mu = 80
        block = 0
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
    block = 0
  []
  [./strain]
    type = ComputeSmallStrain
    displacements = 'disp_x disp_y'
    block = 0
  [../]
  [./stress]
    type = ComputeLinearElasticStress
    block = 0
  [../]
[]

[Executioner]
  type = Transient
  end_time = 5
  dt = 1
[]

[Outputs]
  exodus = true
[]