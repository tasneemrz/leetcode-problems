/**
 * @param {number[]} nums
 * @return {number[]}
 */
var buildArray = function(nums) {
    let n = nums.length;

    for(let i = 0; i < n; i++) {
        nums[i] = nums[i] + (n * (nums[nums[i]] % n));
    }

    for(let i = 0; i < n; i++) {
        nums[i] = Math.floor(nums[i] / n);
    }

    return nums;
};