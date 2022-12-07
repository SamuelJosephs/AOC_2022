module Main where


-- Break Down the array into sub arrays of length 4
subDivide :: Int -> [a] -> [[a]]
subDivide n input@(x:xs) = tail (fst (foldr f ([[]], 1) input))
    where 
        f :: a -> ([[a]], Int) -> ([[a]], Int)
        f c (acc@(y:ys), num) 
            | num == n = (([]:(c:y):ys), 1)
            | otherwise = ((c:y):ys,num + 1)
subDivide _ [] = [[]]

areAllUnique :: Eq a => [a] -> Bool
areAllUnique input@(x:xs)
    | isIn x xs = False
    | otherwise = areAllUnique xs
    where 
        isIn :: Eq a => a -> [a] -> Bool
        isIn c input@(x:xs)
            | c == x = True
            | otherwise = isIn c xs
        isIn c [] = False
areAllUnique [] = True

findFirstUnique :: Eq a => [a] -> Int -> Int
findFirstUnique input@(x:xs) startSize = findFirstUniqueHelper input startSize 0 
    where 
        findFirstUniqueHelper :: Eq a => [a] -> Int -> Int -> Int
        findFirstUniqueHelper input@(x:xs) startSize c
            | areAllUnique $ take startSize input = c + startSize
            | otherwise = findFirstUniqueHelper xs startSize (c + 1) 
        findFirstUnique [] c = 0

        -- findFirstUniqueHelper [] c = 0






test = "bvwbjplbgvbhsrlpgdmjqwftvncz"
test2 = "nznrnfrfntjfmvfwmzdfjlvtqnbhcprsg"
test3 = "mjqjpqmgbljsphdztnvjfqwrcgsmlb"
main :: IO ()
main = do
    msg <- readFile "day_6_input.txt"  

    let loc = findFirstUnique msg 14
    print loc

    
