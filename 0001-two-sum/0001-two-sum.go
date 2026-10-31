func twoSum(nums []int, target int) []int {
    mp := make(map[int]int)

    for i, num := range nums {
        complement := target - num

        if index, found := mp[complement]; found {
            return []int{index, i}
        }

        mp[num] = i
    }

    return []int{}
}