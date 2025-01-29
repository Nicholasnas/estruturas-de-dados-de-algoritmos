from two_sum_ import Solution


solution = Solution()

def test_target_6_retorna_0_1():
    arr1 = [3,3]
    target1 = 6
    assert solution.twoSumBruteForce(arr1, target1) == [0,1]
    assert solution.twoSumPointer(arr1, target1) == [0,1]
    assert solution.twoSumEnumerate(arr1, target1) == [0,1]

def test_target_9_retorna_0_1():
    arr2 = [2,7,11,15]
    target2 = 9
    assert solution.twoSumBruteForce(arr2, target2) == [0,1]
    assert solution.twoSumPointer(arr2, target2) == [0,1]
    assert solution.twoSumEnumerate(arr2, target2) == [0,1]

def test_target_6_retorna_0_2():
    arr3 = [2,3,4]
    target3 = 6
    assert solution.twoSumBruteForce(arr3, target3) == [0,2]
    assert solution.twoSumPointer(arr3, target3) == [0,2]
    assert solution.twoSumEnumerate(arr3, target3) == [0,2]

    

     