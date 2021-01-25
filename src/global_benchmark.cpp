//  Author:  Julian Panetta (jpanetta), julian.panetta@gmail.com
//  Company:  New York University

#include "global_benchmark.h"
#include <iostream>

#ifdef GLOBALBENCHMARK

using namespace std;
using namespace Omni;

static BenchmarkTimer g_timer;
static vector<string> g_benchmarkMessages;
void BENCHMARK_START_TIMER_SECTION(const string &name) { g_timer.startSection(name); }
void  BENCHMARK_STOP_TIMER_SECTION(const string &name) { g_timer.stopSection(name); }
void         BENCHMARK_START_TIMER(const string &name) { g_timer.start(name); }
void          BENCHMARK_STOP_TIMER(const string &name) { g_timer.stop(name); }
void               BENCHMARK_RESET()                   { g_timer.reset(); }

void BENCHMARK_ADD_MESSAGE(const string &msg) {
    g_benchmarkMessages.push_back(msg);
}

void BENCHMARK_CLEAR_MESSAGES() { g_benchmarkMessages.clear(); }

void BENCHMARK_REPORT() {
    for (const auto &message : g_benchmarkMessages)
        cout << message << endl;
    g_timer.report(cout);
}

void BENCHMARK_REPORT_NO_MESSAGES() {
    g_timer.report(cout);
}

#endif
