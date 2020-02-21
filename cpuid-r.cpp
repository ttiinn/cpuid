#include <iostream>
#include <string>

using namespace std;


void cpuID(unsigned regs[4], unsigned eax, unsigned ecx) {
#ifdef _WIN32
  __cpuid((int *)regs, (int)i);

#else
  asm volatile
    ("cpuid" : "=a" (regs[0]), "=b" (regs[1]), "=c" (regs[2]), "=d" (regs[3])
     : "a" (eax), "c" (ecx));
#endif
}

void cpuID_map(unsigned eax, unsigned ecx){
  unsigned regs[4];

  cpuID(regs, eax, ecx);

  printf("[+] cpuid report:");
  printf("    EAX=%#08X", regs[0]);
  printf("    EBX=%#08X", regs[1]);
  printf("    ECX=%#08X", regs[2]);
  printf("    EDX=%#08X", regs[3]);
  printf("\n\n");

  if (eax == 7 and ecx == 0){
    cout << "EBX 00: FSGSBASE. Supports RDFSBASE/RDGSBASE/WRFSBASE/WRGSBASE if 1.              " << ((regs[1] >> 0) & 0x01) << endl;
    cout << "EBX 01: IA32_TSC_ADJUST MSR is supported if 1.                                    " << ((regs[1] >> 1) & 0x01) << endl;
    cout << "EBX 02: SGX                                                                       " << ((regs[1] >> 2) & 0x01) << endl;
    cout << "EBX 03: BMI1                                                                      " << ((regs[1] >> 3) & 0x01) << endl;
    cout << "EBX 04: HLE                                                                       " << ((regs[1] >> 4) & 0x01) << endl;
    cout << "EBX 05: AVX2                                                                      " << ((regs[1] >> 5) & 0x01) << endl;
    cout << "EBX 07: SMEP. Supports Supervisor Mode Execution Protection if 1.                 " << ((regs[1] >> 7) & 0x01) << endl;
    cout << "EBX 06: Reserved                                                                  " << ((regs[1] >> 6) & 0x01) << endl;
    cout << "EBX 08: BMI2                                                                      " << ((regs[1] >> 8) & 0x01) << endl;
    cout << "EBX 09: Supports Enhanced REP MOVSB/STOSB if 1.                                   " << ((regs[1] >> 9) & 0x01) << endl;
    cout << "EBX 10: INVPCID                                                                   " << ((regs[1] >> 10) & 0x01) << endl;
    cout << "EBX 11: RTM                                                                       " << ((regs[1] >> 11) & 0x01) << endl;
    cout << "EBX 12: Supports Platform Quality of Service Monitoring (PQM) capability if 1.    " << ((regs[1] >> 12) & 0x01) << endl;
    cout << "EBX 13: Deprecates FPU CS and FPU DS values if 1.                                 " << ((regs[1] >> 13) & 0x01) << endl;
    cout << "EBX 14: Intel Memory Protection Extensions                                        " << ((regs[1] >> 14) & 0x01) << endl;
    cout << "EBX 15: Supports Platform Quality of Service Enforcement (PQE) capability if 1.   " << ((regs[1] >> 15) & 0x01) << endl;
    cout << "EBX 16: AVX512F                                                                   " << ((regs[1] >> 16) & 0x01) << endl;
    cout << "EBX 17: AVX512DQ                                                                  " << ((regs[1] >> 17) & 0x01) << endl;
    cout << "EBX 18: RDSEED                                                                    " << ((regs[1] >> 18) & 0x01) << endl;
    cout << "EBX 19: ADX                                                                       " << ((regs[1] >> 19) & 0x01) << endl;
    cout << "EBX 20: SMAP                                                                      " << ((regs[1] >> 20) & 0x01) << endl;
    cout << "EBX 21: AVX512_IFMA                                                               " << ((regs[1] >> 21) & 0x01) << endl;
    cout << "EBX 22: Reserved                                                                  " << ((regs[1] >> 22) & 0x01) << endl;
    cout << "EBX 23: CLFLUSHOPT                                                                " << ((regs[1] >> 23) & 0x01) << endl;
    cout << "EBX 24: CLWB                                                                      " << ((regs[1] >> 24) & 0x01) << endl;
    cout << "EBX 25: Intel Processor Trace                                                     " << ((regs[1] >> 25) & 0x01) << endl;
    cout << "EBX 26: AVX512PF (Intel® Xeon Phi™ only.)                                         " << ((regs[1] >> 26) & 0x01) << endl;
    cout << "EBX 27: AVX512ER (Intel® Xeon Phi™ only.)                                         " << ((regs[1] >> 27) & 0x01) << endl;
    cout << "EBX 28: AVX512CD                                                                  " << ((regs[1] >> 28) & 0x01) << endl;
    cout << "EBX 29: SHA                                                                       " << ((regs[1] >> 29) & 0x01) << endl;
    cout << "EBX 30: AVX512BW                                                                  " << ((regs[1] >> 30) & 0x01) << endl;
    cout << "EBX 31: AVX512VL                                                                  " << ((regs[1] >> 31) & 0x01) << endl;
  }
}

int main(int argc, char *argv[]) {
  unsigned eax = 7;
  unsigned ecx = 0;

  if(argc == 2){
    eax = atoi(argv[0]);
  }else if(argc == 3){
    eax = atoi(argv[0]); ecx = atoi(argv[1]);
  }

  cpuID_map(eax, ecx);

  return 0;
}
