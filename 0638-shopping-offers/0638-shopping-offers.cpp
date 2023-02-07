class Solution {
    int _best = INT_MAX;
    public:
        int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
            auto usefulOffers = pruneSpecialOffers(special, price, needs);
            dfs(price, usefulOffers, needs, 0, 0);
            return _best;
        }

        void dfs(const vector<int>& price, 
                 const vector<vector<int>>& special, 
                 vector<int>& needs, 
                 int priceSoFar, 
                 int i) {
            const auto n = price.size();
            if (i >= special.size()) {
                int total = priceSoFar + inner_product(price.begin(), price.end(), needs.begin(), 0);
                _best = min(_best, total);
                return;
            }
            if (priceSoFar >= _best) {
                return; 
            }

            auto needs2 = needs;
            auto price2 = priceSoFar;
            while (true) {
                auto [ok, newNeeds] = tryTakeOffer(special[i], needs2);
                if (ok) {
                    price2 += special[i][n];
                    if (price2 >= _best) {
                        break; 
                    }
                    dfs(price, special, newNeeds, price2, i+1);
                    needs2.swap(newNeeds);
                } else {
                    break;
                }
            }
            dfs(price, special, needs, priceSoFar, i+1);
        }

        static tuple<bool, vector<int>> tryTakeOffer(const vector<int>& offer, const vector<int>& needs) {
            const int n = needs.size();
            vector<int> newNeeds(n);
            for (int i = 0; i < n; ++i) {
                newNeeds[i] = needs[i] - offer[i];
                if (newNeeds[i] < 0) {
                    return {false, {}};
                }
            }
            return {true, std::move(newNeeds)};
        }

        static vector<vector<int>> pruneSpecialOffers(
                const vector<vector<int>>& special, const vector<int>& price, const vector<int>& needs) {
            vector<vector<int>> useful;
            const int n = 0;
            for (int i = 0; i < special.size(); ++i) {
                const auto& offer = special[i];
                int totalPrice = inner_product(price.begin(), price.end(), offer.begin(), 0);
                int specialPrice = offer[n];
                bool exceed = inner_product(needs.begin(), needs.end(), offer.begin(), 
                                            false, bit_or{},
                                           [](int need, int offer) {
                                               return need < offer;
                                           });
                if (specialPrice < totalPrice || !exceed) {
                    useful.push_back(offer);
                }
            }
            return useful;
        }
};