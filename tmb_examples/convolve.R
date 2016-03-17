library(TMB)
compile("convolve.cpp", "-O0 -g")
dyn.load(dynlib("convolve"))
set.seed(123)
data <- list()
set.seed(123)
x <- matrix(rnorm(5*7),5,7)
K <- matrix(rnorm(2*3),2,3)
parameters <- list(x=x,K=K)
obj <- MakeADFun(data,parameters)
obj$fn()
obj$env$f(unlist(parameters),type="double")
obj$report(unlist(parameters))

c1 <- function(x, K){
    y <- array(0, dim(x) - dim(K) + 1)
    Krows <- 1:nrow(K) - 1L
    Kcols <- 1:ncol(K) - 1L
    for(k in 1:nrow(y))
        for(l in 1:ncol(y))
            y[k, l] <- sum( K * x[k + Krows, l + Kcols] )
    y
}

library(numDeriv)
(g1 <- grad(obj$fn, obj$par))
(g2 <- obj$gr(obj$par))
plot(as.vector(g1),as.vector(g2))
abline(0,1)
