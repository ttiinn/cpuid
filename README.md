# CPUID 
This project maps (part of) CPUID result to readable description. 
Help developers to check hardware support for intel cpu features like pt, sgx ...

## Usage
### Build
```
$ g++ cpuid-r.cpp -o cpuid-r.out
```
### Run
Return *Structured Extended Feature Flags Enumeration Leaf* (EAX=7 ECX=0)by default.
```
$ ./cpuid-r.out    
[+] cpuid report:    EAX=00000000    EBX= ...    ECX= ...    EDX= ...

EBX 00: FSGSBASE. Supports RDFSBASE/RDGSBASE/WRFSBASE/WRGSBASE if 1.              1
EBX 01: IA32_TSC_ADJUST MSR is supported if 1.                                    1
EBX 02: SGX                                                                       1
... 
EBX 25: Intel Processor Trace                                                     1
...
```
EAX and ECX can be set as follows
```
$ ./cpuid-r [eax] [ecx]

$ ./cpuid-r.out 1 1             
[+] cpuid report:    EAX= ...    EBX= ...    ECX= ...    EDX= ...         
```

## Progress Report
- [ ] Basic CPUID Information (EAX : 0H ~ 03H)
- [ ] Deterministic Cache Parameters Leaf (EAX = 04H)
- [ ] MONITOR/MWAIT Leaf (EAX = 05H)
- [ ] Thermal and Power Management Leaf (EAX = 06H)
- [x] Structured Extended Feature Flags Enumeration Leaf (EAX = 07H, ECX = 0)
- [ ] Structured Extended Feature Enumeration Sub-leaf (EAX = 07H, ECX = 1)
- [ ] Structured Extended Feature Enumeration Sub-leaves (EAX = 07H, ECX = n, n ≥ 2)
- [ ] ...
- [ ] ...
