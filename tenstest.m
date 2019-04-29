clear; close all; clc;

%% 

rng(10)

n = 5;

mat = 1000*randi(1000,[n n]);
ten = 1000*randi(1000,[n n n]);

test1 = zeros([n n n]);
test2 = zeros([n n n]);

tic
for i = 1:n
    test1(:,:,i) = mat*ten(:,:,i);
end
toc

tic
for i = 1:n
    for j = 1:n
        for k = 1:n
            term = 0;
            for l = 1:n
                term = term + mat(i,l)*ten(l,j,k);
            end
            test2(i,j,k) = term;
        end
    end
end
toc

%%

mat1 = randi(10,[n n]);
rng(5);
mat2 = randi(10,[n n]);

test1 = zeros(n,n);
test2 = zeros(n,n);

test1 = mat1*mat2;

for i = 1:n
    for j = 1:n
        term = 0;
        for k = 1:n
            term = term + mat1(i,k)*mat2(k,j);
        end
        test2(i,j) = term;
    end
end