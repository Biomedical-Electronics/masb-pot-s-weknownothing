# Potentiostat Project 

[//]: # "Maria Bel Bordoy Pont, e-mail: mariabelbordoy@gmail.com, LinkedIn: linkedin.com/in/maria-isabel-bordoy-pont"
[//]: # "Omilén Pangue, e.mail:    , LinkedIn: "

#### What is a potentiostat? 

A [potentiostat](#https://ieeexplore-ieee-org.sire.ub.edu/document/5236124) is the electronic hardware required to monitor and control electrochemical reactions; used to measure the capacitance variations at an electrode/solution interface with recognition elements on the surface of the working electrode. 

The potentiostat utilizes three-electrodes: a) the working electrode (WE), which serves as a surface on with the electrochemical reaction takes place; b) the reference electrode (RE), used to measure the potential at the WE, and c) the auxiliary electrode (AUX), which supplies the needed current required for the electrochemical reaction at the WE. 

<p align="center">
<a href="../assets/imgs/potentiostat.png">
<img src="../assets/imgs/potentiostat.png" alt="Potentiostat" width=400 />
</a>
</p>

> Potentiostat Schematic. [[Source](https://en.wikipedia.org/wiki/Potentiostat)]

Two important electrochemical techniques that can be applied using a potentiostat are cyclic voltammetry and chronoamperometry. 

#### Cyclic Voltammetry

[Cyclic Voltammetry](#https://pubs.acs.org/doi/10.1021/acs.jchemed.7b00361) (CV) is a electrochemical technique commonly employed to investigate the reduction and oxidation processes of molecular species.  It is [performed]([https://chem.libretexts.org/Bookshelves/Analytical_Chemistry/Supplemental_Modules_(Analytical_Chemistry)/Instrumental_Analysis/Cyclic_Voltammetry#:~:text=Cyclic%20Voltammetry%20(CV)%20is%20an,and%20measuring%20the%20resulting%20current.](https://chem.libretexts.org/Bookshelves/Analytical_Chemistry/Supplemental_Modules_(Analytical_Chemistry)/Instrumental_Analysis/Cyclic_Voltammetry#:~:text=Cyclic Voltammetry (CV) is an,and measuring the resulting current.) by cycling the potential of a working electrode, and measuring the resulting current. The potential of the WE is measured against a RE which maintains a constant potential, and it is performed starting from greater potential and ending at a lower potential, to later perform the reverse scan. This performance is repeated during a specific number of cycles. 

A CV system consists of an electrolysis cell, a potentiostat, a current-to-voltage converter, and a data acquisition system. 

#### Chronoamperometry

[Chronoamperometry](#https://www.sciencedirect.com/topics/chemistry/chronoamperometry) is a time-dependent technique where a square-wave potential is applied to the working electrode. The current of the electrode, measured as a function of time, fluctuates according to the diffusion of an analyte from the bulk solution toward the sensor surface.  It is a sensitive technique which does not require labeling of the analyte or bioreceptor. 

## Content

- [Introduction](#potentiostat-project)
  - [What is a potentiostat?](#what-is-a-potentiostat)
  - [Cyclic Voltammetry](#cyclic-voltammetry)
  - [Cronoamperometry](#cronoamperometry)
- [Objective](#objective)
- [Project development](#Project-development) 
  - [Workflow](#workflow)
  - [How does it work?](#How-does-it-work)
  - [Final application](#final-application)
- [Results](#results)
- [Conclusions](#conclusions)



## Objective 

The aim of this project is to perform two types of electrochemical measures: a cyclic voltammetry and a chronoamperometry. 

From this general objectives, different goals can be summed up:

			- Review the literature to learn basic concepts related to potentiostat
			- Programming a microcontroller using STM32CubeIDE platform to perform a cyclic voltammetry and a chronoamperometry 



## Project development 

### Workflow 

The workflow is similar as in other projects developed in this subject. 

<p align="center">
<a href="../assets/imgs/git-tree.png">
<img src="../assets/imgs/git-tree.png" alt="Workflow" width=400 />
</a>
</p>

From the **master** branch, the repository is cloned and a **develop** branch is created. Then, for every functionality, a branch named **feature/---** , where --- is the name of the functionality, is created. If a correction needs to be made, a  branch named **hotfix/--** will be created. 

Finally, all codes from all **feature** branches will be merged with **develop** in order to do a **Pull request** to **master**. 

### How does it work? 

Using the [viSens-S](#https://github.com/Albert-Alvarez/viSens-S/releases/tag/v0.1.0) software

<p align="center">
<a href="../assets/imgs/flow-project.png">
<img src="../assets/imgs/flow-project.png" alt="Flow" width=400 />
</a>
</p>

## Results 

Due to the [COVID-19](#https://covid19.who.int/) situation, in which the project has been carried out, the codes programmed during the project haven't been tested and a proof of concept couldn't be performed. 



## Conclusions 



