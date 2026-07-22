/**
 * @file MirageThreadPool.hpp
 * @author BambooSlips
 * @brief 
 * @version 0.1
 * @date 2025-07-26
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#pragma once

#include <atomic>
#include <condition_variable>
#include <future>
#include <thread>
#include <vector>
#include <queue>
#include <mutex>
#include <cstddef>
#include <functional>
#include <memory>
#include <type_traits>

namespace Mirage
{
    class ThreadPool {
        public:
            ThreadPool(size_t uThreadNum);
            ~ThreadPool();

            template<class F, class... Args>
            std::future<typename std::result_of<F(Args...)>::type>
            Submit(F&& f, Args&&... args);
        
        private:
            std::vector<std::thread>          m_workers;
            std::queue<std::function<void()>> m_tasks;
            std::mutex                        m_queueMutex;
            std::condition_variable           m_condition;
            std::atomic<bool>                 m_stoped;
    };
}

template<class F, class... Args>
std::future<typename std::result_of<F(Args...)>::type>
Mirage::ThreadPool::Submit(F&& f, Args&&... args)
{
    using returnType = typename std::result_of<F(Args...)>::type;

    auto task = std::make_shared<std::packaged_task<returnType()>>(
        std::bind(std::forward<F>(f), std::forward<Args>(args)...)
    );

    std::future<returnType> result = task->get_future();

    {
        std::unique_lock<std::mutex> lock(m_queueMutex);
        if (true == m_stoped)
        {
            throw std::runtime_error("The thread pool has been shut down.");
        }

        m_tasks.emplace([task]() { (*task)(); });
    }

    m_condition.notify_one();

    return result;
}
