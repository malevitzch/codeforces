solveCase :: [Int] -> Bool
solveCase [x] = True
solveCase (x : y : xs) =
  let diff = abs (x - y)
   in (diff == 5 || diff == 7) && solveCase (y : xs)

solveCases :: Int -> IO ()
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

main :: IO ()
main = do
  t <- (readLn :: IO Int)
  solveCases t
