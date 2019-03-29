-- first code ever in haskell!
hello_worlds n = 
    if n > 0
    then do 
		putStrLn "Hello World"
		hello_worlds (n - 1)
	else return ()

-- This part is related to the Input/Output and can be used as it is
-- Do not modify it
main = do
   n <- readLn :: IO Int
   hello_worlds n
