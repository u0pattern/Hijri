#include <windows.h>
#include <stdio.h>
#include <tchar.h>

int _tmain(void) {
    // https://docs.microsoft.com/en-us/windows/win32/api/sysinfoapi/nf-sysinfoapi-getlocaltime
    SYSTEMTIME systemTime;
    GetLocalTime(&systemTime);
    // https://docs.microsoft.com/en-us/windows/win32/api/oleauto/nf-oleauto-SystemTimeToVariantTime
    DATE pvTime;
    SystemTimeToVariantTime(&systemTime, &pvTime);
    // https://docs.microsoft.com/en-us/windows/win32/api/oleauto/nf-oleauto-VarBstrFromDate
    BSTR theTime;
    VarBstrFromDate(pvTime, NULL, VAR_CALENDAR_HIJRI, &theTime);
    _tprintf(theTime);
    return 0;
}