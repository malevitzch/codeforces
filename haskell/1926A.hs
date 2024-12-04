solveCase :: ([Char], Int, Int) -> IO ()
solveCase ([], a, b) =
  if a > b
    then putStrLn "A"
    else putStrLn "B"
solveCase (x : xs, a, b) =
  do
    if x == 'A'
      then solveCase (xs, a + 1, b)
      else solveCase (xs, a, b + 1)

solveCases :: Int -> IO ()
solveCases 0 = return ()
solveCases x = do
  input <- getLine
  solveCase (input, 0, 0)
  solveCases (x - 1)

main :: IO ()
main = do
  t <- (readLn :: IO Int)
  solveCases t
