import Text.Printf
import Data.Char (digitToInt)

solveCase :: [Char] -> IO () 
solveCase [a, op, b] = do
  let x = (digitToInt a)
  let y = (digitToInt b)
  if x == y then printf "%d=%d\n" x y
  else if x < y then printf "%d<%d\n" x y
  else printf "%d>%d\n" x y

solveCases :: Int -> IO ()
solveCases 0 = return ()
solveCases x = do
  input <- getLine
  solveCase input
  solveCases (x-1)
main :: IO ()
main = do
  t <- (readLn :: IO Int)
  solveCases t
