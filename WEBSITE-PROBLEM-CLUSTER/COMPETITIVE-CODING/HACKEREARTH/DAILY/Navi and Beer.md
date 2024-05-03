---
title: Navi and Beer
published: 2024-05-02
tags: ["Implementation","Basic-Programming","Very-Easy","Ready","Mathematics","Approved"]
category: HACKEREARTH
draft: false
---

# [02-05-2024. Navi and Beer](https://www.hackerearth.com/problem/algorithm/navi-and-beer-1/)

## Problem :
Navi is at the Beer Bar where he has ordered **N** beers. After seeing his love with the beers, Bar's Manager has decided to make as much money as they can by asking Navi to pay **K * i<sup>3</sup>** Rupees for the i<sup>th</sup> beer. But Navi has only **M** Rupees in his purse. So you are required to lent him some money so that he can still be able to pay for all of the **N** beers.
### Input Format :
- First line will contain **T** (No. of test cases).
- Each test case will contain only one line having three space separated integers : **N**, **K** and **M**
### Output Format :
* For every test case, print the required answer in a new line.
### Constraints :
- 1 ≤ **T** ≤ 10<sup>5</sup>
- 1 ≤ **N, K** ≤ 10<sup>3</sup>
- 1 ≤ **M** ≤ 10<sup>6</sup>
### Sample:
| INPUT       | OUPUT |
| ----------- | ----- |
| 1<br>2 2 10 | 8     |
### Explanation : 
Total Money required is : 2 * 1<sup>3</sup> + 2 * 2<sup>3</sup> = 18 but he already has 10 so answer is 8.
## CODE : 
* [CHECK THE CPP CODE IN REPOSITORY]
* [Check Author's Solution]
* [Check Tester's Solution]

```cpp
#include <iostream>
using namespace std;
int main() {
    long long int t,n,k,m;
    cin >> t;
    while(t-- > 0)
    {
        cin>>n>>k>>m;
        long long int total=0;
        for(long long int i=1;i<=n;i++)
        {
            total=total + (k * i*i*i);
        }
        if (total > m)
        {
            cout << total - m <<endl;
        }
        else
        {
            cout<<"0"<<endl;
        }
    }
}
```
## TESTCASES:
* [testcase-input-01](https://raw.githubusercontent.com/ikshvaku01/ikshvaku01-garden-docs/main/WEBSITE-PROBLEM-CLUSTER/HACKEARTH/TESTCASES/9378df6c-95674417b0df-d66ee4d2c971/testcase-input-01.txt) [testcase-output-01](https://raw.githubusercontent.com/ikshvaku01/ikshvaku01-garden-docs/main/WEBSITE-PROBLEM-CLUSTER/HACKEARTH/TESTCASES/9378df6c-95674417b0df-d66ee4d2c971/testcase-output-01.txt)
* [testcase-input-02](https://raw.githubusercontent.com/ikshvaku01/ikshvaku01-garden-docs/main/WEBSITE-PROBLEM-CLUSTER/HACKEARTH/TESTCASES/9378df6c-95674417b0df-d66ee4d2c971/testcase-input-02.txt) [testcase-output-02](https://raw.githubusercontent.com/ikshvaku01/ikshvaku01-garden-docs/main/WEBSITE-PROBLEM-CLUSTER/HACKEARTH/TESTCASES/9378df6c-95674417b0df-d66ee4d2c971/testcase-output-02.txt)
* [testcase-input-03](https://raw.githubusercontent.com/ikshvaku01/ikshvaku01-garden-docs/main/WEBSITE-PROBLEM-CLUSTER/HACKEARTH/TESTCASES/9378df6c-95674417b0df-d66ee4d2c971/testcase-input-03.txt) [testcase-output-03](https://raw.githubusercontent.com/ikshvaku01/ikshvaku01-garden-docs/main/WEBSITE-PROBLEM-CLUSTER/HACKEARTH/TESTCASES/9378df6c-95674417b0df-d66ee4d2c971/testcase-output-03.txt)
* [testcase-input-04](https://raw.githubusercontent.com/ikshvaku01/ikshvaku01-garden-docs/main/WEBSITE-PROBLEM-CLUSTER/HACKEARTH/TESTCASES/9378df6c-95674417b0df-d66ee4d2c971/testcase-input-04.txt) [testcase-output-04](https://raw.githubusercontent.com/ikshvaku01/ikshvaku01-garden-docs/main/WEBSITE-PROBLEM-CLUSTER/HACKEARTH/TESTCASES/9378df6c-95674417b0df-d66ee4d2c971/testcase-output-04.txt)
* [testcase-input-05](https://raw.githubusercontent.com/ikshvaku01/ikshvaku01-garden-docs/main/WEBSITE-PROBLEM-CLUSTER/HACKEARTH/TESTCASES/9378df6c-95674417b0df-d66ee4d2c971/testcase-input-05.txt) [testcase-output-05](https://raw.githubusercontent.com/ikshvaku01/ikshvaku01-garden-docs/main/WEBSITE-PROBLEM-CLUSTER/HACKEARTH/TESTCASES/9378df6c-95674417b0df-d66ee4d2c971/testcase-output-05.txt)
* [testcase-input-06](https://raw.githubusercontent.com/ikshvaku01/ikshvaku01-garden-docs/main/WEBSITE-PROBLEM-CLUSTER/HACKEARTH/TESTCASES/9378df6c-95674417b0df-d66ee4d2c971/testcase-input-06.txt) [testcase-output-06](https://raw.githubusercontent.com/ikshvaku01/ikshvaku01-garden-docs/main/WEBSITE-PROBLEM-CLUSTER/HACKEARTH/TESTCASES/9378df6c-95674417b0df-d66ee4d2c971/testcase-output-06.txt)
* [testcase-input-07](https://raw.githubusercontent.com/ikshvaku01/ikshvaku01-garden-docs/main/WEBSITE-PROBLEM-CLUSTER/HACKEARTH/TESTCASES/9378df6c-95674417b0df-d66ee4d2c971/testcase-input-07.txt) [testcase-output-07](https://raw.githubusercontent.com/ikshvaku01/ikshvaku01-garden-docs/main/WEBSITE-PROBLEM-CLUSTER/HACKEARTH/TESTCASES/9378df6c-95674417b0df-d66ee4d2c971/testcase-output-07.txt)
* [testcase-input-08](https://raw.githubusercontent.com/ikshvaku01/ikshvaku01-garden-docs/main/WEBSITE-PROBLEM-CLUSTER/HACKEARTH/TESTCASES/9378df6c-95674417b0df-d66ee4d2c971/testcase-input-08.txt) [testcase-output-08](https://raw.githubusercontent.com/ikshvaku01/ikshvaku01-garden-docs/main/WEBSITE-PROBLEM-CLUSTER/HACKEARTH/TESTCASES/9378df6c-95674417b0df-d66ee4d2c971/testcase-output-08.txt)
* [testcase-input-09](https://raw.githubusercontent.com/ikshvaku01/ikshvaku01-garden-docs/main/WEBSITE-PROBLEM-CLUSTER/HACKEARTH/TESTCASES/9378df6c-95674417b0df-d66ee4d2c971/testcase-input-09.txt) [testcase-output-09](https://raw.githubusercontent.com/ikshvaku01/ikshvaku01-garden-docs/main/WEBSITE-PROBLEM-CLUSTER/HACKEARTH/TESTCASES/9378df6c-95674417b0df-d66ee4d2c971/testcase-output-09.txt)
* [testcase-input-10](https://raw.githubusercontent.com/ikshvaku01/ikshvaku01-garden-docs/main/WEBSITE-PROBLEM-CLUSTER/HACKEARTH/TESTCASES/9378df6c-95674417b0df-d66ee4d2c971/testcase-input-10.txt) [testcase-output-10](https://raw.githubusercontent.com/ikshvaku01/ikshvaku01-garden-docs/main/WEBSITE-PROBLEM-CLUSTER/HACKEARTH/TESTCASES/9378df6c-95674417b0df-d66ee4d2c971/testcase-output-10.txt)
## SIMILAR PROBLEMS:
* [Life, the Universe, and Everything]
* [Mehta's Dilemma]
* [A bitwise pair]