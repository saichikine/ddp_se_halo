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

%%

res1 = zeros(size(ten));
temp = zeros(size(ten));

tic
for i = 1:n
    temp(i,:,:) = mat1'*squeeze(ten(i,:,:))*mat1;
end
for i = 1:n
    res1(:,:,i) = mat2*ten(:,:,i) + temp(:,:,i);
end
toc

res2 = zeros(size(ten));
tic
for i = 1:n
    for j = 1:n
        for k = 1:n
            comp1 = 0;
            comp2 = 0;
            for gam1 = 1:n
                comp1 = comp1 + mat2(i,gam1)*ten(gam1,j,k); % matrix part
                for gam2 = 1:n
                    comp2 = comp2 + ten(i,gam1,gam2)*mat1(gam1,j)*mat1(gam2,k); % tensor part
                end
            end
            res2(i,j,k) = comp1 + comp2;
        end
    end
end
toc