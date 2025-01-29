from typing import List

class Solution:
    def twoSumBruteForce(self, nums:List[int], target:int) -> List[int]:
        "Complexidade O(n²)- muito ruim"
        for i in range(len(nums)-1):
            for j in range(i+1, len(nums)):
                if (nums[i]+nums[j]) == target:
                    return [i,j]
    
    def twoSumPointer(self, nums:List[int], target:int) -> List[int]:
        "Complexidade O(n)- linear - bom"        
        start = 0
        end = len(nums) - 1

        while start < end:
            soma = nums[start] + nums[end]

            if soma == target:
                return [start, end]
            
            elif soma < target:
                start += 1
            else:
                end -= 1

    def twoSumEnumerate(self, nums, target) -> List[int]:
        nums_index:dict = {}

        for index, valor in enumerate(nums):
            diff = target - valor
            if diff in nums_index:
                return [nums_index[diff], index] # Retornar o index do pat
            
            nums_index[valor] = index  # Adicionar o valor ao dicionario
        
        return [] # Vazio

if __name__ == "__main__":
    arr3 = [3,3]
    target3 = 6
    s = Solution()
    print('Enumerate: ',s.twoSumEnumerate(arr3, target3))
    print('Pointer: ', s.twoSumPointer(arr3, target3))





        
