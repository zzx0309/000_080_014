/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__char_file_printf_05.c
Label Definition File: CWE134_Uncontrolled_Format_String.label.xml
Template File: sources-sinks-05.tmpl.c
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * BadSource: file Read input from a file
 * GoodSource: Copy a fixed string into data
 * Sinks: printf
 *    GoodSink: printf with "%s" as the first argument and data as the second
 *    BadSink : printf with only data as an argument
 * Flow Variant: 05 Control flow: if(staticTrue) and if(staticFalse)
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

#ifdef _WIN32
#define FILENAME "C:\\temp\\file.txt"
#else
#define FILENAME "/tmp/file.txt"
#endif

/* The two variables below are not defined as "const", but are never
   assigned any other value, so a tool should be able to identify that
   reads of these will always return their initialized values. */
static int staticTrue = 1; /* true */
static int staticFalse = 0; /* false */

#ifndef OMITBAD

void CWE134_Uncontrolled_Format_String__char_file_printf_05_bad()
{
    char * data;
    char dataBuffer[100] = "";
    data = dataBuffer;
    if(staticTrue)
    {
        {
            /* Read input from a file */
            size_t dataLen = strlen(data);
            FILE * pFile;
            /* if there is room in data, attempt to read the input from a file */
            if (100-dataLen > 1)
            {
                pFile = fopen(FILENAME, "r");
                if (pFile != NULL)
                {
                    /* POTENTIAL FLAW: Read data from a file */
                    if (fgets(data+dataLen, (int)(100-dataLen), pFile) == NULL) //SLIVER_SOURCE
                    {
                        printLine("fgets() failed");
                        /* Restore NUL terminator if fgets fails */
                        data[dataLen] = '\0';
                    }
                    fclose(pFile);
                }
            }
        }
    }
    if(staticTrue)
    {
        /* POTENTIAL FLAW: Do not specify the format allowing a possible format string vulnerability */
        printf(data); //SLIVER_SINK
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G1() - use badsource and goodsink by changing the second staticTrue to staticFalse */
static void goodB2G1()
{
    char * data;
    char dataBuffer[100] = "";
    data = dataBuffer;
    if(staticTrue)
    {
        {
            /* Read input from a file */
            size_t dataLen = strlen(data);
            FILE * pFile;
            /* if there is room in data, attempt to read the input from a file */
            if (100-dataLen > 1)
            {
                pFile = fopen(FILENAME, "r");
                if (pFile != NULL)
                {
                    /* POTENTIAL FLAW: Read data from a file */
                    if (fgets(data+dataLen, (int)(100-dataLen), pFile) == NULL) //SLIVER_SOURCE
                    {
                        printLine("fgets() failed");
                        /* Restore NUL terminator if fgets fails */
                        data[dataLen] = '\0';
                    }
                    fclose(pFile);
                }
            }
        }
    }
    if(staticFalse)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* FIX: Specify the format disallowing a format string vulnerability */
        printf("%s\n", data); //SLIVER_SINK
    }
}

/* goodB2G2() - use badsource and goodsink by reversing the blocks in the second if */
static void goodB2G2()
{
    char * data;
    char dataBuffer[100] = "";
    data = dataBuffer;
    if(staticTrue)
    {
        {
            /* Read input from a file */
            size_t dataLen = strlen(data);
            FILE * pFile;
            /* if there is room in data, attempt to read the input from a file */
            if (100-dataLen > 1)
            {
                pFile = fopen(FILENAME, "r");
                if (pFile != NULL)
                {
                    /* POTENTIAL FLAW: Read data from a file */
                    if (fgets(data+dataLen, (int)(100-dataLen), pFile) == NULL) //SLIVER_SOURCE
                    {
                        printLine("fgets() failed");
                        /* Restore NUL terminator if fgets fails */
                        data[dataLen] = '\0';
                    }
                    fclose(pFile);
                }
            }
        }
    }
    if(staticTrue)
    {
        /* FIX: Specify the format disallowing a format string vulnerability */
        printf("%s\n", data); //SLIVER_SINK
    }
}

/* goodG2B1() - use goodsource and badsink by changing the first staticTrue to staticFalse */
static void goodG2B1()
{
    char * data;
    char dataBuffer[100] = "";
    data = dataBuffer;
    if(staticFalse)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* FIX: Use a fixed string that does not contain a format specifier */
        strcpy(data, "fixedstringtest");
    }
    if(staticTrue)
    {
        /* POTENTIAL FLAW: Do not specify the format allowing a possible format string vulnerability */
        printf(data); //SLIVER_SINK
    }
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the first if */
static void goodG2B2()
{
    char * data;
    char dataBuffer[100] = "";
    data = dataBuffer;
    if(staticTrue)
    {
        /* FIX: Use a fixed string that does not contain a format specifier */
        strcpy(data, "fixedstringtest");
    }
    if(staticTrue)
    {
        /* POTENTIAL FLAW: Do not specify the format allowing a possible format string vulnerability */
        printf(data); //SLIVER_SINK
    }
}

void CWE134_Uncontrolled_Format_String__char_file_printf_05_good()
{
    goodB2G1();
    goodB2G2();
    goodG2B1();
    goodG2B2();
}

#endif /* OMITGOOD */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    CWE134_Uncontrolled_Format_String__char_file_printf_05_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE134_Uncontrolled_Format_String__char_file_printf_05_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif

//SLIVER_SOURCE:56--->SLIVER_SINK:70 YES
//SLIVER_SOURCE:56--->SLIVER_SINK:116 NO
//SLIVER_SOURCE:56--->SLIVER_SINK:153 NO
//SLIVER_SOURCE:56--->SLIVER_SINK:176 NO
//SLIVER_SOURCE:56--->SLIVER_SINK:194 NO
//SLIVER_SOURCE:97--->SLIVER_SINK:70 NO
//SLIVER_SOURCE:97--->SLIVER_SINK:116 YES
//SLIVER_SOURCE:97--->SLIVER_SINK:153 NO
//SLIVER_SOURCE:97--->SLIVER_SINK:176 NO
//SLIVER_SOURCE:97--->SLIVER_SINK:194 NO
//SLIVER_SOURCE:139--->SLIVER_SINK:70 NO
//SLIVER_SOURCE:139--->SLIVER_SINK:116 NO
//SLIVER_SOURCE:139--->SLIVER_SINK:153 YES
//SLIVER_SOURCE:139--->SLIVER_SINK:176 NO
//SLIVER_SOURCE:139--->SLIVER_SINK:194 NO