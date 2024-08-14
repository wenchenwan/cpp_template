/* ==================================================================
 * Copyright (c) 2023, wenchenwan.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the
 * distribution.
 * 3. All advertising materials mentioning features or use of this software
 * must display the following acknowledgement:
 * This product includes software developed by the xxx Group. and
 * its contributors.
 * 4. Neither the name of the Group nor the names of its contributors may
 * be used to endorse or promote products derived from this software
 * without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY xxx,GROUP AND CONTRIBUTORS
 * ===================================================================
 *
 *
 * Author:  Wen Chenwan (wenchenwan@outlook.com).
 * @version 0.1
 * @date 2024-04-20
 * @file template_class_template_member.hpp
 * @brief Implement an example of a template class that contains template
 * members
 */

namespace testTemplate {
template <typename T>
class testMemberTemplate {
   private:
    /* data */
   public:
    testMemberTemplate(T a);
    ~testMemberTemplate();

    template <typename U>
    void test() {
        std::cout << typeid(U).name() << std::endl;
    }
};
template <typename T>
testMemberTemplate<T>::testMemberTemplate(T a) {
    std::cout << typeid(a).name() << std::endl;
}
template <typename T>
testMemberTemplate<T>::~testMemberTemplate() {}

} // namespace testTemplate
