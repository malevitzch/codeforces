solveCase :: Int -> Int -> Int
solveCase x y = max x y + 1

solveCases :: Int -> IO ()
solveCases 0 = return ()
solveCases t = do
  input <- getLine
  let [x, y] = map read (words input) :: [Int]
  print (solveCase x y)
  solveCases (t - 1)

main :: IO ()
main = do
  t <- (readLn :: IO Int)
  solveCases t
