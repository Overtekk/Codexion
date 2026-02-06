<p align="center">
  <img src="assets/codexion.png" width="250" />
</p>
<h3 align="center">
  <em>Master the race for resources before the deadline masters you!</em>
</h3>

---

<div align="center">
<img src="https://img.shields.io/badge/No score%20-inactive?logo=42&logoColor=ffff" />
<img src="https://img.shields.io/badge/bonus-none-inactive"/>
<img src="https://img.shields.io/badge/date completed-none-inactive"/>
</div>

## ⚠️ Disclaimer

- **Full Portfolio:** This repository focuses on this specific project. You can find my entire 42 curriculum 👉 [here](https://github.com/Overtekk/42).
- **Subject Rules:** I strictly follow the rules regarding 42 subjects; I cannot share the PDFs, but I explain the concepts in this README.
- **Archive State:** The code is preserved exactly as it was during evaluation (graded state). I do not update it, so you can see my progress and mistakes from that time.
- **Academic Integrity:** I encourage you to try the project yourself first. Use this repo only as a reference, not for copy-pasting. Be patient, you will succeed.

---

## ✏️ Quick Start

```bash

make

./codexion number_of_coders time_to_burnout time_to_compile time_to_debug time_to_refactor number_of_compiles_required dongle_cooldown scheduler
```
---

## 📂 Description
### 📜 Summary:
The goal is to create a competition between differents coders using **thread**.\
There is one or more **coders**. Each can do 3 things at a time:
- **compile**
- **debug**
- **refactor**

They compile, then debug, then refactory and start compile right after finishint refactoring.\
Coders can **burns out** starting the simulation or when they finish compiling. They need to compile before the timer hits 0.\
Do to that, they need **USB dongles**. They are many dongles that coders. To compile, they need a dongle in each hands. Once compiling is done, they start debugging, then they start refactoring.\
If each coders have compiled a certain amount of time, the simulation can stop.\
They can't communicate and they do not know when a coder will burns out.

It's a compilation because codes are in a circular hub. So, **Coder 1** sit next to **Coder 2** and **Coder 4** (assuming they are 4).\
They are **4 USB dongles**.

Here a diagram to better understanding:

```
			  CODER 1
             (Compile)
             /       \
      Dongle D       Dongle A
   (Taken by 1)      (Taken by 1)
       /                    \
    CODER 4                CODER 2
(Wait Dongle D)         (Wait Dongle A)
      \                     /
      Dongle C         Dongle B
    (Taken by 4)     (Taken by 2)
             \       /
               CODER 3
               (Wait)
```

### 📝 Rules:

- Each coder need to be represented by a **thread** (using `pthread_create`).
- If there is **1 coder**, it will **burns out** since there is only **1 USB dongle**.
- To prevent coders from duplicating dongles, **dongle's state must be protected** with a **mutex** (`pthread_mutex_t`). A condition variable (`pthread_cond_t`) may be
used to manage waiting queues.
- There is a **scheduler** to manage priority:
- **FIFO**: First In, First Out. Follow the queue to give dongles.
- **EDF**: Earliest Deadline First. The coder that will burn out first will take the dongles.
- The program must guarantee liveness. So coders should not burns out under edf scheduling, provided the parameters are feasible.
- A separate **monitor** thread must detect burnout precisely and stop the simulation.
The burnout log must be printed **within 10 ms** of the actual burnout time.
- Logging must be **serialized** so that two messages never interleave on a single line (use a **mutex** to protect output).
- Code must compile with **-Wall -Wextra -Werror -pthread**.
- A priority queue **(heap)** for **FIFO**/**EDF** scheduling must be implemented.
- No memory leaks.
- Global variables are forbidden.
- Logs must follows rules (see below).
- Those arguments are mandatory:

|Arguments|Value|Description|
|:-------:|:---:|:---------:|
|number_of_coders|>=1|Number of coders ans also the number of donglers|
|time_to_burnout|>=1|(in ms)Time before a coder will burns out since the last compilation. Start at the beginning of the simulation|
|time_to_compile|>=1|Time it takes for a coder to compile. During that time, it need to hold two dongles|
|time_to_debug|>=1|Time a coder spend debugging|
|time_to_refactor|>=1|Time a coder will spend refactoring. After completing this phase, it will immediately attempts to acquire dongles and start compiling again|
|number_of_compiles_required|>=1|If all coders have compiled at least this many times, the simulation stops||
|dongle_cooldown|>=1|Time before a dongle can be used again||
|scheduler|`fifo` or `edf`|The arbitratin policy used by dongles||

### 📮 Makefile:

Makefile need to have those rules:
- **NAME** variable
- all
- clean
- fclean
- re

It must not relink.

### 🏷️ Authorized Functions:

|Thread managements|Mutex|Thread cond|Memory management|Printing|Other|
|:----------------:|:---:|:----------:|:--------------:|:------:|:---:|
|pthread_create|pthread_mutex_init|pthread_cond_init|malloc|write|gettimeofday|
|pthread_join|pthread_mutex_lock|pthread_cond_wait|free|fprintf|usleep|
||pthread_mutex_unlock|pthread_cond_timedwait|memset|printf|strcmp|
||pthread_mutex_destroy|pthread_cond_broadcast|||strlen|
|||pthread_cond_destroy|||atoi|

### 💻 Logs:

Any state change of a coder must be formatted as follows:
- timestamp_in_ms X has taken a dongle
- timestamp_in_ms X is compiling
- timestamp_in_ms X is debugging
- timestamp_in_ms X is refactoring
- timestamp_in_ms X burned out

*X will be the coder number*

Rules:
- A displayed state message should not be mixed up with another message.
- A message announcing that a coder burned out should be displayed no more than 10 ms after the actual burnout.

---

## 💡 Instructions

1. First, clone this repository:
```bash
git clone https://github.com/Overtekk/
```

2. Run the program:
```bash
make
# time is in ms
./codexion number_of_coders time_to_burnout time_to_compile time_to_debug time_to_refactor number_of_compiles_required dongle_cooldown scheduler
```

---

## 🛸 Blocking cases handled

---

## 🕛 Thread synchronization mechanisms

---

## 📚 Resources

### Threads:
- https://www.geeksforgeeks.org/c/thread-functions-in-c-c/

---
