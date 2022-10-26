# Schedulers
* [FreeBSD (ULE) vs Linux scheduler(CFS) - stackoverflow](https://stackoverflow.com/questions/14918797/difference-between-freebsd-scheduler-and-linux-scheduler)
* [FreeBSD ULE vs Linux scheduler CFS - usenix](https://www.usenix.org/system/files/conference/atc18/atc18-bouron.pdf)
* [FreeBSD scheduler](https://papers.freebsd.org/2020/BSDcan/mckusick-Scheduling_in_the_FreeBSD_Kernel.files/mckusick-Scheduling_in_the_FreeBSD_Kernel.pdf)
* [MacOS kern/sched.h - github](https://github.com/apple/darwin-xnu/blob/main/osfmk/kern/sched.h)
* [MacOS XNU vs Linux sched](https://alexdelorenzo.dev/programming/2018/08/23/ionice.html)

**Linux** - CFS is short for Completely Fair Scheduler. The most notable difference is that CFS is not based on run queues for process selection. Instead, it uses a red-black tree with O(log N) complexity that is indexed by CPU time spent.

**FreeBSD** - ULE is the successor to the traditional BSD scheduler. It offers much improved performance on SMP systems as well as uniprocessor systems. It follows a more traditional design with run queues and time slices. It strives to be fair, but can be instructed to favor interactive processes.

**Qnx** - To meet the needs of various applications, QNX Neutrino provides these scheduling policies:
* [FIFO scheduling — SCHED_FIFO](https://www.qnx.com/developers/docs/7.1/#com.qnx.doc.neutrino.prog/topic/overview_FIFO_scheduling.html) (voluntarily relinquishes control (e.g., it blocks), or is preempted by a higher-priority thread)
* [Round-robin scheduling — SCHED_RR](https://www.qnx.com/developers/docs/7.1/#com.qnx.doc.neutrino.prog/topic/overview_Round_robin_scheduling.html) (voluntarily relinquishes control, or is preempted by a higher-priority thread, or consumes its timeslice)
* [Sporadic scheduling — SCHED_SPORADIC](https://www.qnx.com/developers/docs/7.1/#com.qnx.doc.neutrino.prog/topic/overview_Sporadic_scheduling.html) (to provide a capped limit on the execution time of a thread within a given period of time.)

**macOS** - [The OS X scheduler](https://developer.apple.com/library/archive/documentation/Darwin/Conceptual/KernelProgramming/scheduler/scheduler.html#//apple_ref/doc/uid/TP30000905-CH211-BABFGDHA) is derived from the scheduler used in OSFMK 7.3. Thread priority bands: Normal, System high priority, Kernel mode only, Real-time threads.
  