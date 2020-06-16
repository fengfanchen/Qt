#pragma once


#define ExportFunc _declspec(dllexport)

extern "C" ExportFunc int Add(int a, int b);
extern "C" ExportFunc int Sub(int a, int b);