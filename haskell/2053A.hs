solveCase :: [Int] -> Bool
solveCases :: Int -> IO ()
main :: IO ()
solveCase [x] = False
solveCase (x : y : xs) =
  2 * min x y > max x y || solveCase (y : xs)

solveCases 0 = return ()
solveCases x = do
  n <- (readLn :: IO Int)
  input <- getLine
  let arr = map read (words input) :: [Int]
  let result = solveCase arr
  if result
    then putStrLn "YES"
    else putStrLn "NO"
  solveCases (x - 1)

main = do
  t <- (readLn :: IO Int)
  solveCases t
