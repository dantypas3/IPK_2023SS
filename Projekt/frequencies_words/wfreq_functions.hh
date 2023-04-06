#pragma once

#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>


std::map<std::string, int> get_frequencies();

std::unordered_map<std::string, int> get_frequencies2();

void print_frequencies(const std::map<std::string, int>& frequencies);

void print_frequencies2(const std::unordered_map<std::string, int>& frequencies);