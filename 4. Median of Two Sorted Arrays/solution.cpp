#include <iostream>
#include <vector>


static double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
    const int size = nums1.size() + nums2.size();
    int i1 = 0, i2 = 0;

    double median;
    if (size % 2) {
        const int medianIndex = (size - 1) / 2;

        while (i1 < nums1.size() || i2 < nums2.size()) {
            if (i1 < nums1.size() && i2 < nums2.size()) {
                if (medianIndex == (i1 + i2)) {
                    median = nums1[i1] < nums2[i2] ? nums1[i1] : nums2[i2];
                    break;
                }
                nums1[i1] < nums2[i2] ? nums1[i1++] : nums2[i2++];
            } else if (i1 >= nums1.size()) {
                if (medianIndex == (i1 + i2)) {
                    median = nums2[i2];
                    break;
                }
                nums2[i2++];
            } else {
                if (medianIndex == (i1 + i2)) {
                    median = nums1[i1];
                    break;
                }
                nums1[i1++];
            }
        }
    } else {
        const int firstMedianIndex = (size - 1) / 2;

        while (i1 < nums1.size() || i2 < nums2.size()) {
            if (i1 < nums1.size() && i2 < nums2.size()) {
                if (firstMedianIndex == (i1 + i2)) {
                    median = nums1[i1] < nums2[i2] ? nums1[i1] : nums2[i2];
                } else if (firstMedianIndex < (i1 + i2)) {
                    median += nums1[i1] < nums2[i2] ? nums1[i1] : nums2[i2];
                    median /= 2.0;
                    break;
                }
                nums1[i1] < nums2[i2] ? nums1[i1++] : nums2[i2++];
            } else if (i1 >= nums1.size()) {
                if (firstMedianIndex == (i1 + i2)) {
                    median = (nums2[i2] + nums2[i2+1]) / 2.0;
                    break;
                } else if (firstMedianIndex < (i1 + i2)) {
                    median += nums2[i2];
                    median /= 2.0;
                    break;
                }
                nums2[i2++];
            } else {
                if (firstMedianIndex == (i1 + i2)) {
                    median = (nums1[i1] + nums1[i1+1]) / 2.0;
                    break;
                } else if (firstMedianIndex < (i1 + i2)) {
                    median += nums1[i1];
                    median /= 2.0;
                    break;
                }
                nums1[i1++];
            }
        }
    }

    return median;
}

int main() {

    { // Testcase 1
        std::vector<int> nums1 = {1,3}, nums2 = {2};

        const double median = findMedianSortedArrays(nums1, nums2);

        std::cout << "Median 1: " << median << std::endl;
    }

    { // Testcase 2
        std::vector<int> nums1 = {1,2}, nums2 = {3,4};

        const double median = findMedianSortedArrays(nums1, nums2);

        std::cout << "Median 2: " << median << std::endl;
    }

    return 0;
}