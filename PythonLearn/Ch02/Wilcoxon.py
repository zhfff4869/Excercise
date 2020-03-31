from scipy import stats

def wilcoxon_rank_sum_test(x, y):
	res = stats.mannwhitneyu(x ,y)
	print(res)

if __name__ == "__main__":
    x1=[9,5,8,7,10,6,7]
    x2=[7,4,5,6,3,6,4,4]
    wilcoxon_rank_sum_test(x1,x2)