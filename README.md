# Leetcode-1615.-Maximal-Network-Rank
# 🏙️ Maximal Network Rank (C++)

This project contains **two efficient approaches** to solving the **Maximal Network Rank** problem. The goal is to find the maximum sum of connected roads between any two distinct cities in a network, counting the shared direct road only once.

---

## 📌 Problem Statement

Given:
- `n` cities labeled from `0` to `n-1`
- A list of `roads` where `roads[i] = [ai, bi]` represents a bidirectional road between cities `ai` and `bi`

**Task:**  
Return the *maximum network rank* between any two different cities.  
A **network rank** of two cities is defined as the total number of roads connected to either city. If they share a direct road, count it only once.

---

## 🚀 Approaches

### ✅ Approach 1: Using Adjacency Sets

- **Data Structure:** `unordered_map<int, unordered_set<int>>`
- Stores connections for each city as a set
- Loop through every pair `(i, j)` and compute the total degree
- Subtract 1 if there's a direct connection

#### Pros:
- Cleaner code with intuitive set operations

#### Cons:
- `unordered_set` may have slightly slower lookups than boolean matrix in some cases

---

### ✅ Approach 2: Using Degree Array & Connection Matrix

- **Data Structure:**  
  - `vector<int> deg` for storing degree of each city  
  - `vector<vector<bool>> isconnected` as a boolean matrix for direct connections
- Faster lookups using precomputed matrix

#### Pros:
- Constant time lookup for direct connections
- Slightly faster for large datasets

#### Cons:
- Slightly higher memory usage due to `O(n²)` boolean matrix

---

## 🧠 Time & Space Complexity

| Approach | Time Complexity | Space Complexity | Notes |
|---------|----------------|------------------|-------|
| Set-based | `O(n²)` | `O(n + m)` | `m` is number of roads |
| Matrix-based | `O(n²)` | `O(n²)` | Faster lookup, higher space |

---

## 📦 Example

### Input:
```cpp
n = 4;
roads = {{0,1},{0,3},{1,2},{1,3}};
Output:
4
Explanation:
Cities 1 and 3 have 3 and 2 roads respectively.
They share a road, so 3 + 2 - 1 = 4.
