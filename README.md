# Philosophers
>_I never thought philosophy would be so deadly_

# Index
* [What is Philosophers?](#philosophers)
* [Done](#done)
* [TO-DO](#to-do)
* [Some examples](#examples)
* [Final Grade](#grade)

## Philosophers
**The purpose of this project is to solve the *'dining philosophers problem'* using multithreading**

We will need to develop a program that enables a group of philosophers to share limited resources while avoiding different issues like deadlock. 

*The main instructions for this project are:*

      • One or more philosophers are sitting at a round table doing one of three things:
      eating, thinking, or sleeping.

      • There are some forks on the table. It is assumed that a philosopher must eat with two forks, one for each hand.

      • Each time a philosopher has finished eating, he will drop his forks and start sleeping. Then, he will start thinking.

      • The simulation stops when a philosopher dies.

## Done

- [X] Sends thread x philo (argv[1])

- [X] Mutex protects forks, and terminal

- [X] Program stops when either all finished eating or when a philosopher dies

- [X] Philos dont die with LazyTester

## To do

- [ ] All_finished variable not working correctly and program wont stop until later

- [ ] Check final leaks

- [ ] What happens with 1 philosopher only?

- [ ] Change all 'philo_id' instances to '(philo_id + 1)'

## Examples
`1 800 200 200` dies

`5 800 200 200` lives

`5 800 200 200` all live and eat 7 times

`4 410 200 200` lives

`4 310 200 100` dies

### More extreme cases:

`3 310 103 103` lives

`3 310 104 104` dies

## Grade
> This project got a **100**/100 in **_42_** school

<p align="center">
<img width="194" alt="Captura" src="https://github.com/shoganaix/42PushSwap/assets/123943292/a706aec1-2095-45b3-b583-19fbcaf614c9">
</p>

<p align="center">
<sub>NO BONUSES</sub>
</p>
